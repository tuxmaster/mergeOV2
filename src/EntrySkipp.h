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
 * 1 byte	T: type (always 1)
 * 4 bytes	Number of bytes in the file, including and starting at this record,
 *			that contain data for POI enclosed in the given rectangle
 * 4 bytes	X1: longitude coordinate of the west edge of the rectangle
 * 4 bytes	Y1: latitude coordinate of the south edge of the rectangle
 * 4 bytes	X2: longitude coordinate of the east edge of the rectangle
 * 4 bytes	Y2: latitude coordinate of the north edge of the rectangle
 */
#ifndef ENTRYSKIPP_H
#define ENTRYSKIPP_H
#include "EntryBase.h"
class EntrySkipp : public EntryBase
{
	public:
		const unsigned char& type_id() const  Q_DECL_OVERRIDE { return EntrySkipp::p_typeID; }
		void create(const QByteArray& data) Q_DECL_OVERRIDE {}

	private:
		static const unsigned char p_typeID;
};
const unsigned char EntrySkipp::p_typeID = 1;
#endif // ENTRYSKIPP_H
