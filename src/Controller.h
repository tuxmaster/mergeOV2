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
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QtCore>

class Controller : public QObject
{
		Q_OBJECT
	public:
		explicit Controller(QObject *parent = Q_NULLPTR);
		Controller(QObject* parrent, const QString& src_dir, const QString& dst_file);

	signals:
		void		quit();

	public slots:

	private slots:
		void		start();

	private:
			QDir	p_srcPath;
			QFile	p_dstFile;
};

#endif // CONTROLLER_H
