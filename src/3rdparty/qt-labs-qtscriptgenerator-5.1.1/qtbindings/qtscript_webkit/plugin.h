#include <QtScript/QScriptExtensionPlugin>
#include <QtScript/QScriptValue>
#include <QtScript/QScriptEngine>
#include <QtPlugin>


void qtscript_initialize_com_trolltech_qt_webkit_bindings(QScriptValue &);

class com_trolltech_qt_webkit_ScriptPlugin : public QScriptExtensionPlugin
{
Q_OBJECT
Q_PLUGIN_METADATA(IID "com.trolltech.qt.webkit.scriptPlugin")
public:
    QStringList keys() const;
    void initialize(const QString &key, QScriptEngine *engine);
};

