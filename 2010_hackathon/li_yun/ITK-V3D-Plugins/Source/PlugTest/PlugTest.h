#ifndef __PlugTest_H__
#define __PlugTest_H__

#include "V3DITKPluginDefaultHeader.h"

class PlugTestPlugin : public QObject, public V3DPluginInterface
{
  Q_OBJECT
  Q_INTERFACES(V3DPluginInterface)
  V3DITKPLUGIN_DEFAULT_CLASS_DECLARATION_BODY(PlugTest);
};

#endif
