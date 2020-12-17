// Copyright (c) 2014 The Bitcoin developers
//Copyright (c) 2017-2019 The PIVX developers
//Copyright (c) 2020 The BinJit developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "networkstyle.h"

#include "guiconstants.h"

#include <QApplication>

static const struct {
    const char* networkId;
    const char* appName;
    const char* appIcon;
    const char* titleAddText;
    const char* splashImage;
} network_styles[] = {
    {"main", QAPP_APP_NAME_DEFAULT, ":/icons/bitcoin", "", ":/bg-splash-png"},
    {"test", QAPP_APP_NAME_TESTNET, ":/icons/bitcoin", QT_TRANSLATE_NOOP("SplashScreen", "[testnet]"), ":/bg-splash-png"},
    {"regtest", QAPP_APP_NAME_TESTNET, ":/icons/bitcoin", "[regtest]", ":/bg-splash-png"}};
static const unsigned network_styles_count = sizeof(network_styles) / sizeof(*network_styles);

// titleAddText needs to be const char* for tr()
NetworkStyle::NetworkStyle(const QString& appName, const QString& appIcon, const char* titleAddText, const QString& splashImage) : appName(appName),
                                                                                                                                   appIcon(appIcon),
                                                                                                                                   titleAddText(qApp->translate("SplashScreen", titleAddText)),
                                                                                                                                   splashImage(splashImage)
{
}

const NetworkStyle* NetworkStyle::instantiate(const QString& networkId)
{
    for (unsigned x = 0; x < network_styles_count; ++x) {
        if (networkId == network_styles[x].networkId) {
            return new NetworkStyle(
                network_styles[x].appName,
                network_styles[x].appIcon,
                network_styles[x].titleAddText,
                network_styles[x].splashImage);
        }
    }
    return 0;
}
