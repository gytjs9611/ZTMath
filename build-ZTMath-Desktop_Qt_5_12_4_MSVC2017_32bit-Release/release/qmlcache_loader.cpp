#include <QtQml/qqmlprivate.h>
#include <QtCore/qdir.h>
#include <QtCore/qurl.h>

static const unsigned char qt_resource_tree[] = {
0,
0,0,0,0,2,0,0,0,20,0,0,0,1,0,0,0,
76,0,0,0,0,0,1,0,0,0,0,0,0,1,52,0,
0,0,0,0,1,0,0,0,0,0,0,0,238,0,0,0,
0,0,1,0,0,0,0,0,0,1,240,0,0,0,0,0,
1,0,0,0,0,0,0,0,38,0,0,0,0,0,1,0,
0,0,0,0,0,1,90,0,0,0,0,0,1,0,0,0,
0,0,0,0,196,0,0,0,0,0,1,0,0,0,0,0,
0,1,126,0,0,0,0,0,1,0,0,0,0,0,0,1,
152,0,0,0,0,0,1,0,0,0,0,0,0,2,54,0,
0,0,0,0,1,0,0,0,0,0,0,0,112,0,0,0,
0,0,1,0,0,0,0,0,0,2,140,0,0,0,0,0,
1,0,0,0,0,0,0,1,18,0,0,0,0,0,1,0,
0,0,0,0,0,2,108,0,0,0,0,0,1,0,0,0,
0,0,0,1,202,0,0,0,0,0,1,0,0,0,0,0,
0,2,20,0,0,0,0,0,1,0,0,0,0,0,0,0,
160,0,0,0,0,0,1,0,0,0,0,0,0,0,8,0,
0,0,0,0,1,0,0,0,0,0,0,2,76,0,0,0,
0,0,1,0,0,0,0,0,0,2,180,0,0,0,0,0,
1,0,0,0,0};
static const unsigned char qt_resource_names[] = {
0,
1,0,0,0,47,0,47,0,12,13,168,82,252,0,77,0,
97,0,105,0,110,0,80,0,97,0,103,0,101,0,46,0,
113,0,109,0,108,0,16,3,182,248,92,0,67,0,111,0,
109,0,109,0,111,0,110,0,66,0,117,0,116,0,116,0,
111,0,110,0,46,0,113,0,109,0,108,0,15,1,203,28,
60,0,83,0,101,0,108,0,101,0,99,0,116,0,80,0,
97,0,110,0,101,0,108,0,46,0,113,0,109,0,108,0,
21,10,19,233,252,0,81,0,117,0,101,0,115,0,116,0,
105,0,111,0,110,0,72,0,97,0,108,0,102,0,80,0,
97,0,110,0,101,0,108,0,46,0,113,0,109,0,108,0,
15,13,149,38,124,0,81,0,117,0,101,0,115,0,116,0,
66,0,97,0,110,0,110,0,101,0,114,0,46,0,113,0,
109,0,108,0,18,4,53,114,188,0,80,0,97,0,103,0,
101,0,83,0,116,0,97,0,116,0,101,0,80,0,97,0,
110,0,101,0,108,0,46,0,113,0,109,0,108,0,15,2,
178,101,92,0,79,0,112,0,116,0,105,0,111,0,110,0,
80,0,97,0,110,0,101,0,108,0,46,0,113,0,109,0,
108,0,14,12,143,204,252,0,65,0,110,0,115,0,119,0,
101,0,114,0,80,0,97,0,103,0,101,0,46,0,113,0,
109,0,108,0,16,2,154,193,220,0,81,0,117,0,101,0,
115,0,116,0,105,0,111,0,110,0,80,0,97,0,103,0,
101,0,46,0,113,0,109,0,108,0,15,3,210,28,28,0,
66,0,117,0,116,0,116,0,111,0,110,0,80,0,97,0,
110,0,101,0,108,0,46,0,113,0,109,0,108,0,10,4,
204,72,156,0,66,0,97,0,110,0,110,0,101,0,114,0,
46,0,113,0,109,0,108,0,22,6,29,146,60,0,81,0,
117,0,101,0,115,0,116,0,67,0,111,0,110,0,116,0,
101,0,110,0,116,0,115,0,80,0,97,0,110,0,101,0,
108,0,46,0,113,0,109,0,108,0,16,12,227,150,156,0,
83,0,101,0,108,0,101,0,99,0,116,0,79,0,98,0,
106,0,101,0,99,0,116,0,46,0,113,0,109,0,108,0,
15,2,225,38,124,0,76,0,101,0,118,0,101,0,108,0,
66,0,117,0,116,0,116,0,111,0,110,0,46,0,113,0,
109,0,108,0,14,13,39,112,156,0,76,0,101,0,118,0,
101,0,108,0,80,0,97,0,110,0,101,0,108,0,46,0,
113,0,109,0,108,0,8,8,1,90,92,0,109,0,97,0,
105,0,110,0,46,0,113,0,109,0,108,0,13,14,230,155,
220,0,69,0,114,0,114,0,111,0,114,0,80,0,97,0,
103,0,101,0,46,0,113,0,109,0,108,0,13,12,178,29,
220,0,84,0,121,0,112,0,101,0,80,0,97,0,110,0,
101,0,108,0,46,0,113,0,109,0,108,0,17,10,181,86,
220,0,67,0,104,0,101,0,99,0,107,0,66,0,111,0,
120,0,80,0,97,0,110,0,101,0,108,0,46,0,113,0,
109,0,108,0,16,15,242,193,28,0,81,0,117,0,101,0,
115,0,116,0,105,0,111,0,110,0,73,0,116,0,101,0,
109,0,46,0,113,0,109,0,108};
static const unsigned char qt_resource_empty_payout[] = { 0, 0, 0, 0, 0 };
QT_BEGIN_NAMESPACE
extern Q_CORE_EXPORT bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);
QT_END_NAMESPACE
namespace QmlCacheGeneratedCode {
namespace _0x5f__QuestionItem_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__CheckBoxPanel_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__TypePanel_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__ErrorPage_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__main_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__LevelPanel_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__LevelButton_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__SelectObject_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__QuestContentsPanel_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__Banner_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__ButtonPanel_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__QuestionPage_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__AnswerPage_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__OptionPanel_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__PageStatePanel_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__QuestBanner_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__QuestionHalfPanel_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__SelectPanel_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__CommonButton_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__MainPage_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}

}
namespace {
struct Registry {
    Registry();
    QHash<QString, const QQmlPrivate::CachedQmlUnit*> resourcePathToCachedUnit;
    static const QQmlPrivate::CachedQmlUnit *lookupCachedUnit(const QUrl &url);
};

Q_GLOBAL_STATIC(Registry, unitRegistry)


Registry::Registry() {
        resourcePathToCachedUnit.insert(QStringLiteral("/QuestionItem.qml"), &QmlCacheGeneratedCode::_0x5f__QuestionItem_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/CheckBoxPanel.qml"), &QmlCacheGeneratedCode::_0x5f__CheckBoxPanel_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/TypePanel.qml"), &QmlCacheGeneratedCode::_0x5f__TypePanel_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/ErrorPage.qml"), &QmlCacheGeneratedCode::_0x5f__ErrorPage_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/main.qml"), &QmlCacheGeneratedCode::_0x5f__main_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/LevelPanel.qml"), &QmlCacheGeneratedCode::_0x5f__LevelPanel_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/LevelButton.qml"), &QmlCacheGeneratedCode::_0x5f__LevelButton_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/SelectObject.qml"), &QmlCacheGeneratedCode::_0x5f__SelectObject_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/QuestContentsPanel.qml"), &QmlCacheGeneratedCode::_0x5f__QuestContentsPanel_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Banner.qml"), &QmlCacheGeneratedCode::_0x5f__Banner_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/ButtonPanel.qml"), &QmlCacheGeneratedCode::_0x5f__ButtonPanel_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/QuestionPage.qml"), &QmlCacheGeneratedCode::_0x5f__QuestionPage_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/AnswerPage.qml"), &QmlCacheGeneratedCode::_0x5f__AnswerPage_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/OptionPanel.qml"), &QmlCacheGeneratedCode::_0x5f__OptionPanel_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/PageStatePanel.qml"), &QmlCacheGeneratedCode::_0x5f__PageStatePanel_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/QuestBanner.qml"), &QmlCacheGeneratedCode::_0x5f__QuestBanner_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/QuestionHalfPanel.qml"), &QmlCacheGeneratedCode::_0x5f__QuestionHalfPanel_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/SelectPanel.qml"), &QmlCacheGeneratedCode::_0x5f__SelectPanel_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/CommonButton.qml"), &QmlCacheGeneratedCode::_0x5f__CommonButton_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/MainPage.qml"), &QmlCacheGeneratedCode::_0x5f__MainPage_qml::unit);
    QQmlPrivate::RegisterQmlUnitCacheHook registration;
    registration.version = 0;
    registration.lookupCachedQmlUnit = &lookupCachedUnit;
    QQmlPrivate::qmlregister(QQmlPrivate::QmlUnitCacheHookRegistration, &registration);
QT_PREPEND_NAMESPACE(qRegisterResourceData)(/*version*/0x01, qt_resource_tree, qt_resource_names, qt_resource_empty_payout);
}
const QQmlPrivate::CachedQmlUnit *Registry::lookupCachedUnit(const QUrl &url) {
    if (url.scheme() != QLatin1String("qrc"))
        return nullptr;
    QString resourcePath = QDir::cleanPath(url.path());
    if (resourcePath.isEmpty())
        return nullptr;
    if (!resourcePath.startsWith(QLatin1Char('/')))
        resourcePath.prepend(QLatin1Char('/'));
    return unitRegistry()->resourcePathToCachedUnit.value(resourcePath, nullptr);
}
}
int QT_MANGLE_NAMESPACE(qInitResources_qml)() {
    ::unitRegistry();
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_qml))
int QT_MANGLE_NAMESPACE(qCleanupResources_qml)() {
    return 1;
}
