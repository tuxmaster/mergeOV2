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
 * Coordinates are stored as 4−byte integers representing a WGS84 longitude or latitude,
 * multiplied by100,000 and rounded to the nearest integer. As such, an X−coordinate
 * should always be a value between−18,000,000 and +18,000,000, and a Y−coordinate should
 * be a value between −9,000,000 and +9,000,000.
 */
#ifndef ENTRYBASE_H
#define ENTRYBASE_H
#include <QtCore>

class EntryBase
{
	public:
		virtual const unsigned char& type_id() const = 0;
};

#endif // ENTRYBASE_H
