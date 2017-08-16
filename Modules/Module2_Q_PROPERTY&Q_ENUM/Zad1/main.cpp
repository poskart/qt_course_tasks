#include <QApplication>
#include <QListView>
#include <QtCore/QMetaProperty>
#include <QStandardItemModel>

int main( int argc, char **argv )
{
  QApplication app( argc, argv );

  QListView *list = new QListView();

  QObject *object = list;
  const QMetaObject * metaobject = object->metaObject();
  int count = metaobject->propertyCount();

  QStandardItemModel model( count, 1 );
  for( int r = 0; r < count; r++ )
  {
      QMetaProperty metaproperty = metaobject->property(r);
      const char *name = metaproperty.name();
      QVariant value = object->property(name);
      QStandardItem *item = new QStandardItem( QString("Name:%0, Value:%1").arg(name).arg(value.toString()));
      model.setItem(r, 0, item);
  }

  model.setHorizontalHeaderItem( 0, new QStandardItem( "Właściwości:" ) );

  list->setModel( &model );
  list->show();

  return app.exec();
}
