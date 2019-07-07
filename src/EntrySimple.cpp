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
#include "EntrySimple.h"

const unsigned char& EntrySimple::type_id() const
{
	 return EntrySimple::p_typeID;
}
void EntrySimple::create(const QByteArray& data)
{
	qint32 size = *reinterpret_cast<const qint32*>(data.mid(1, 4).constData());
	qint32 latitude=*reinterpret_cast<const qint32*>(data.mid(9,4).constData());
	qint32 longitude=*reinterpret_cast<const qint32*>(data.mid(5,4).constData());
	QString name=data.mid(14, size-15);
	m_position.setLatitude(latitude/100000.0);
	m_position.setLongitude(longitude/100000.0);
	m_name = name;
}
const QGeoCoordinate& EntrySimple::position() const
{
	return m_position;
}
const QString& EntrySimple::name() const
{
	return m_name;;
}
const unsigned char EntrySimple::p_typeID = 2;
QDebug operator<<(QDebug dbg, const EntrySimple &entry)
{
	dbg.nospace()<<"Simple entry.";
	dbg.space()<<"Position:"<<entry.position();
	dbg.space()<<"Name:"<<QString(entry.name()).replace("\"","");
	return dbg.maybeSpace();
}
