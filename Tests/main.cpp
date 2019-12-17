#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <trompeloeil_catch.hpp>

#include <QCoreApplication>
#include <QtTest>
#include <QtWidgets>
#include <QtGui>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>

int main( int argc, char* argv[] )
{
    QCoreApplication a(argc, argv);

    QTEST_SET_MAIN_SOURCE_PATH
    int result = Catch::Session().run( argc, argv );

    return ( result < 0xff ? result : 0xff );
}
