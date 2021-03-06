/**
 * Copyright (c) 2011-2013 by Andrew Mustun. All rights reserved.
 * 
 * This file is part of the QCAD project.
 *
 * QCAD is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * QCAD is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with QCAD.
 */

/**
 * \defgroup ecma_draw_arc Arc Drawing Tools
 * \ingroup ecma_draw
 *
 * \brief This module contains ECMAScript implementations of various arc drawing tools.
 */
include("../Draw.js");

/**
 * \class Arc
 * \brief Base class for all arc drawing tools.
 * \ingroup ecma_draw_arc
 */
function Arc(guiAction) {
    Draw.call(this, guiAction);
}

Arc.prototype = new Draw();
Arc.includeBasePath = includeBasePath;

Arc.prototype.beginEvent = function() {
    Draw.prototype.beginEvent.call(this);

    if (!isNull(this.getGuiAction()) && this.getGuiAction().objectName=="ArcMenu") {
        EAction.showCadToolBarPanel("ArcToolsPanel");
        this.terminate();
    }
};

Arc.getMenu = function() {
    var menu = EAction.getSubMenu(
        Draw.getMenu(), 300, Arc.getTitle(), "arc", Arc.includeBasePath + "/Arc.svg"
    );
    menu.setProperty("scriptFile", Arc.includeBasePath + "/Arc.js");
    return menu;
};

Arc.getToolBar = function() {
    var tb = EAction.getToolBar(Arc.getTitle(), "Arc");
    tb.visible = false;
    return tb;
};

Arc.getCadToolBarPanel = function() {
    var mtb = Draw.getCadToolBarPanel();
    var actionName = "ArcMenu";
    if (!isNull(mtb) && mtb.findChild(actionName)==undefined) {
        var action = new RGuiAction(qsTr("Arc Tools"), mtb);
        action.setScriptFile(Arc.includeBasePath + "/Arc.js");
        action.objectName = actionName;
        action.setRequiresDocument(true);
        action.setIcon(Arc.includeBasePath + "/Arc.svg");
        action.setStatusTip(qsTr("Show arc tools"));
        action.setDefaultShortcut(new QKeySequence("w,a"));
        action.setNoState();
        action.setProperty("SortOrder", 300);
        action.setDefaultCommands(["arcmenu"]);
        CadToolBarPanel.prototype.addAction.call(mtb, action);
    }

    var tb = EAction.getCadToolBarPanel(Arc.getTitle(), "ArcToolsPanel", true);
    return tb;
};

Arc.getTitle = function() {
    return qsTr("&Arc");
};

Arc.prototype.getTitle = function() {
    return Arc.getTitle();
};
