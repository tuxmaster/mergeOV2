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
/*
 * Definition
 * 1 byte		T: type (always 2)
 * 4 bytes		L: length of this record in bytes (including the T and L fields)
 * 4 bytes		X: longitude coordinate of the POI
 * 4 bytes		Y: latitude coordinate of the POI
 * L−13 bytes	Name: zero−terminated ASCII string specifying the name of the POI
 */
#ifndef ENTRYSIMPLE_H
#define ENTRYSIMPLE_H
#include "EntryBase.h"
#include <QtPositioning/QGeoCoordinate>

class EntrySimple: public EntryBase
{
	public:
		const unsigned char&		type_id() const Q_DECL_OVERRIDE;
		void						create(const QByteArray& data) Q_DECL_OVERRIDE;
		const QGeoCoordinate&		position() const;
		const QString&				name() const;

	private:
		static const unsigned char	p_typeID;
		QGeoCoordinate				m_position;
		QString						m_name;
};
QDebug operator<<(QDebug dbg, const EntrySimple &entry);
#endif // ENTRYSIMPLE_H
