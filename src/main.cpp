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
#include <QtCore>
#include "EntryDelete.h"
#include "EntrySimple.h"
#include "EntryExtended.h"
#include "EntrySkipp.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	EntryDelete* d = new EntryDelete();
	EntrySimple* s = new EntrySimple();
	EntryExtended* e = new EntryExtended();
	EntrySkipp* sk = new EntrySkipp();
	qInfo()<<"delete " << d->type_id();
	qInfo()<<"simple "<< s->type_id();
	qInfo()<<"extended "<< e->type_id();
	qInfo()<<"skipp " <<sk->type_id();
	return a.exec();
}
