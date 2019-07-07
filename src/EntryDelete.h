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
 * 1 byte		T: type (always 0)
 * 4 bytes		L: length of this record in bytes (including the T and L fields)
 * L−5 bytes	bytes to ignore (content undefined)
 */
#ifndef ENTRYDELETE_H
#define ENTRYDELETE_H
#include "EntryBase.h"
class EntryDelete: public EntryBase
{
	public:
		const unsigned char& type_id() const  Q_DECL_OVERRIDE { return EntryDelete::p_typeID; }
		void create(const QByteArray& data) Q_DECL_OVERRIDE {}

	private:
		static const unsigned char p_typeID;
};
const unsigned char EntryDelete::p_typeID = 0;
#endif // ENTRYDELETE_H
