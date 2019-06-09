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

ReadOV2::ReadOV2(const QFileInfo &file)
{
	p_file.setFileName(file.absoluteFilePath());
	p_resultValid = false;
}
bool ReadOV2::read()
{
	QByteArray buffer;
	if (p_file.open(QIODevice::ReadOnly))
	{
		qInfo()<<"processing "<<p_file.fileName();
		buffer = p_file.readAll();
		p_result = new QByteArray();
		p_result->append(buffer);
		p_file.close();
		p_resultValid = true;
		return true;
	}
	return false;
}
QByteArray* ReadOV2::result()
{
	if (p_resultValid)
		return p_result;
	return new QByteArray;
}
