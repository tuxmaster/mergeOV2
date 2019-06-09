/*
	Copyright (C) 2019 Frank Büttner tuxmaster@users.noreply.github.com

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>
*/
#include "Controller.h"
#include "ReadOV2.h"
#include <QtConcurrent>

Controller::Controller(QObject *parent) : QObject(parent)
{
}
Controller::Controller(QObject* parrent, const QString& src_dir, const QString& dst_file): QObject(parrent)
{
	p_srcPath.setPath(src_dir);
	p_dstFile.setFileName(dst_file);
	QTimer::singleShot(0,this,&Controller::start);
}
QByteArray* process(const QFileInfo& file)
{
	ReadOV2 reader(file);
	reader.read();
	return reader.result();
}
void Controller::start()
{
	QStringList filters;
	filters<<"*.ov2";
	QFileInfoList to_process = p_srcPath.entryInfoList(filters,QDir::Files | QDir::Readable | QDir::Hidden);
	if (to_process.empty())
	{
		qCritical()<<trUtf8("The source directory %1 don't have any ov2 files.").arg(p_srcPath.absolutePath());
		QCoreApplication::exit(1);
		return;
	}
	QFuture<QByteArray*> result = QtConcurrent::mapped(to_process, process);
	QByteArray* all = new QByteArray();
	result.waitForFinished();
	for(QByteArray* p:result.results())
	{
		all->append(*p);
		delete p;
	}
	if(p_dstFile.exists())
	{
		qCritical()<<trUtf8("File %1 alredy exist. Canncel proccessing").arg(p_dstFile.fileName());
		QCoreApplication::exit(1);
	} else {
		if(p_dstFile.open(QIODevice::WriteOnly))
		{
			if (p_dstFile.write(*all) == -1)
			{
				qCritical()<<trUtf8("Error while writing the file.");
				QCoreApplication::exit(1);
			} else
				qInfo()<<trUtf8("File %1 saved.").arg(p_dstFile.fileName());
			p_dstFile.close();
		}
	}
	delete all;
	QCoreApplication::exit();
}
