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
#include "config.h"
#include "Controller.h"


int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	QCoreApplication::setApplicationVersion(VERSION);
	QCoreApplication::setApplicationName(APP_NAME);
	QCommandLineParser parser;
	parser.setApplicationDescription(QCoreApplication::translate("main","Merge .ov2 files."));
	parser.addHelpOption();
	parser.addVersionOption();
	parser.addPositionalArgument("source", QCoreApplication::translate("main", "Directory with ov2 files."));
	parser.addPositionalArgument("result", QCoreApplication::translate("main", "Target ov2 file."));
	parser.process(a);
	const QStringList args = parser.positionalArguments();
	if(args.size() != 2)
		parser.showHelp();
	new Controller(&a, args[0], args[1]);
	return a.exec();
}
