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
#include "RTextEntity.h"
#include "RExporter.h"

RPropertyTypeId RTextEntity::PropertyCustom;
RPropertyTypeId RTextEntity::PropertyHandle;
RPropertyTypeId RTextEntity::PropertyType;
RPropertyTypeId RTextEntity::PropertyBlock;
RPropertyTypeId RTextEntity::PropertyLayer;
RPropertyTypeId RTextEntity::PropertyLinetype;
RPropertyTypeId RTextEntity::PropertyLineweight;
RPropertyTypeId RTextEntity::PropertyColor;
RPropertyTypeId RTextEntity::PropertyDrawOrder;

RPropertyTypeId RTextEntity::PropertySimple;
RPropertyTypeId RTextEntity::PropertyPositionX;
RPropertyTypeId RTextEntity::PropertyPositionY;
RPropertyTypeId RTextEntity::PropertyPositionZ;
RPropertyTypeId RTextEntity::PropertyText;
RPropertyTypeId RTextEntity::PropertyPlainText;
RPropertyTypeId RTextEntity::PropertyFontName;
RPropertyTypeId RTextEntity::PropertyHeight;
RPropertyTypeId RTextEntity::PropertyAngle;
RPropertyTypeId RTextEntity::PropertyBold;
RPropertyTypeId RTextEntity::PropertyItalic;
RPropertyTypeId RTextEntity::PropertyLineSpacingFactor;
RPropertyTypeId RTextEntity::PropertyHAlign;
RPropertyTypeId RTextEntity::PropertyVAlign;


RTextEntity::RTextEntity(RDocument* document, const RTextData& data, RObject::Id objectId) :
    RTextBasedEntity(document, objectId), data(document, data) {
}

RTextEntity::~RTextEntity() {
}

void RTextEntity::init() {
    RTextEntity::PropertyCustom.generateId(typeid(RTextEntity), RObject::PropertyCustom);
    RTextEntity::PropertyHandle.generateId(typeid(RTextEntity), RObject::PropertyHandle);
    RTextEntity::PropertyType.generateId(typeid(RTextEntity), REntity::PropertyType);
    RTextEntity::PropertyBlock.generateId(typeid(RTextEntity), REntity::PropertyBlock);
    RTextEntity::PropertyLayer.generateId(typeid(RTextEntity), REntity::PropertyLayer);
    RTextEntity::PropertyLinetype.generateId(typeid(RTextEntity), REntity::PropertyLinetype);
    RTextEntity::PropertyLineweight.generateId(typeid(RTextEntity), REntity::PropertyLineweight);
    RTextEntity::PropertyColor.generateId(typeid(RTextEntity), REntity::PropertyColor);
    RTextEntity::PropertyDrawOrder.generateId(typeid(RTextEntity), REntity::PropertyDrawOrder);

    RTextEntity::PropertySimple.generateId(typeid(RTextEntity), RTextBasedEntity::PropertySimple);
    RTextEntity::PropertyPositionX.generateId(typeid(RTextEntity), RTextBasedEntity::PropertyPositionX);
    RTextEntity::PropertyPositionY.generateId(typeid(RTextEntity), RTextBasedEntity::PropertyPositionY);
    RTextEntity::PropertyPositionZ.generateId(typeid(RTextEntity), RTextBasedEntity::PropertyPositionZ);
    RTextEntity::PropertyText.generateId(typeid(RTextEntity), RTextBasedEntity::PropertyText);
    RTextEntity::PropertyPlainText.generateId(typeid(RTextEntity), RTextBasedEntity::PropertyPlainText);
    RTextEntity::PropertyFontName.generateId(typeid(RTextEntity), RTextBasedEntity::PropertyFontName);
    RTextEntity::PropertyHeight.generateId(typeid(RTextEntity), RTextBasedEntity::PropertyHeight);
    RTextEntity::PropertyAngle.generateId(typeid(RTextEntity), RTextBasedEntity::PropertyAngle);
    RTextEntity::PropertyBold.generateId(typeid(RTextEntity), RTextBasedEntity::PropertyBold);
    RTextEntity::PropertyItalic.generateId(typeid(RTextEntity), RTextBasedEntity::PropertyItalic);
    RTextEntity::PropertyLineSpacingFactor.generateId(typeid(RTextEntity), RTextBasedEntity::PropertyLineSpacingFactor);
    RTextEntity::PropertyHAlign.generateId(typeid(RTextEntity), RTextBasedEntity::PropertyHAlign);
    RTextEntity::PropertyVAlign.generateId(typeid(RTextEntity), RTextBasedEntity::PropertyVAlign);
}

void RTextEntity::print(QDebug dbg) const {
    dbg.nospace() << "RTextEntity(";
    RTextBasedEntity::print(dbg);
    dbg.nospace() << ")";
}
