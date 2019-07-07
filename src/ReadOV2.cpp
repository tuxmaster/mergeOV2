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
#include "ReadOV2.h"
#include "EntryDelete.h"
#include "EntrySkipp.h"
#include "EntryExtended.h"
#include "EntrySimple.h"

ReadOV2::ReadOV2(const QFileInfo &file)
{
	m_file.setFileName(file.absoluteFilePath());
	m_resultValid = false;
}
bool ReadOV2::read()
{
	QByteArray buffer;
	if (m_file.open(QIODevice::ReadOnly))
	{
		int pos = 0;
		quint32 size;
		qInfo()<<"processing "<<m_file.fileName();
		buffer = m_file.readAll();
		m_file.close();
		m_result = new QByteArray();
		EntryBase* entry=Q_NULLPTR;

		while (pos != -1 )
		{
			//qDebug()<<"Type: "<<QString::number(buffer[pos],16).toUpper();
			size = *reinterpret_cast<const quint32*>(buffer.mid(pos+1, 4).constData());
			//qDebug()<<"size: "<<size;
			switch (buffer[pos])
			{
				case 0:
					//qDebug()<<"delete type";
					entry = new EntryDelete();
					break;
				case 1:
					//qDebug()<<"skipp type";
					entry = new EntrySkipp();
					break;
				case 2:
					//qDebug()<<"simple type";
					entry = new EntrySimple();
					break;
				case 3:
					//qDebug()<<"extended type";
					entry = new EntryExtended();
					break;
				default:
						qWarning()<<QCoreApplication::translate("ReadOV2","File %1 damaged.").arg(m_file.fileName());
						return false;
			}
			if (entry)
			{
				entry->create(buffer.mid(pos,static_cast<int>(size)));
				qDebug()<< *dynamic_cast<EntrySimple*>(entry);
			}
			m_result->append(buffer.mid(pos,static_cast<int>(size)));
			pos = pos + static_cast<int>(size);
			if (pos == buffer.size())
				pos = -1;
		}
		m_resultValid = true;
		return true;
	}
	return false;
}
QByteArray* ReadOV2::result()
{
	if (m_resultValid)
		return m_result;
	return new QByteArray;
}
