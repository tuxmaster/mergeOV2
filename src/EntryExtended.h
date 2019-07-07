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
 * 1 byte			T: type (always 3)
 * 4 bytes			L: length of this record in bytes (including the T and L fields)
 * 4 bytes			X: longitude coordinate of the POI
 * 4 bytes			Y: latitude coordinate of the POI
 * P bytes			Name: zero−terminated ASCII string specifying the name of the POI
 * Q bytes			Unique ID: zero−terminated string specifying the unique ID of the POI
 * L−P−Q−13 bytes	Extra data: zero−terminated string, not used yet
 */
#ifndef ENTRYEXTENDED_H
#define ENTRYEXTENDED_H
#include "EntrySimple.h"
class EntryExtended: public EntrySimple
{
	public:
		const unsigned char& type_id() const  Q_DECL_OVERRIDE { return EntryExtended::p_typeID; }
		void create(const QByteArray& data) Q_DECL_OVERRIDE {}

	private:
		static const unsigned char p_typeID;
};
const unsigned char EntryExtended::p_typeID = 3;
#endif // ENTRYEXTENDED_H
