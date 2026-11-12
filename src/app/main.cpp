#include <gdal_priv.h>

#include <QApplication>
#include <QLabel>
#include <QString>

using namespace Qt::StringLiterals;

int main( int argc, char *argv[] )
{
  QApplication app( argc, argv );
  GDALAllRegister();

  const QString text = u"Hello hobo-gis!\nQt %1 / GDAL %2"_s.arg( QString::fromUtf( qVersion() ), QString::fromUtf8( GDALVersionInfo( "RELEASE_NAME" ) ) );

  QLabel label( text );
  label.setAlignment( Qt::AlignCenter );
  label, resize( 400, 200 );
  label.show();

  // イベントループ: ウィンドウが閉じられるまで、ここで入力を待ち続ける
  return app.exec();
}
