/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */

#ifndef INCLUDED_SC_SOURCE_FILTER_XML_XMLCODENAMEPROVIDER_HXX
#define INCLUDED_SC_SOURCE_FILTER_XML_XMLCODENAMEPROVIDER_HXX

#include <com/sun/star/container/XNameAccess.hpp>
#include <cppuhelper/implbase.hxx>

class ScDocument;

class XMLCodeNameProvider : public ::cppu::WeakImplHelper< css::container::XNameAccess >
{
    ScDocument* mpDoc;
    OUString msDocName;
    OUString msCodeNameProp;

    static bool _getCodeName( const css::uno::Any& aAny,
                           OUString& rCodeName );

public:
    explicit XMLCodeNameProvider(ScDocument* pDoc);
    virtual ~XMLCodeNameProvider();

    virtual sal_Bool SAL_CALL hasByName( const OUString& aName )
        throw (css::uno::RuntimeException, std::exception ) override;

    virtual css::uno::Any SAL_CALL getByName( const OUString& aName )
        throw (css::container::NoSuchElementException,
               css::lang::WrappedTargetException,
               css::uno::RuntimeException, std::exception) override;

    virtual css::uno::Sequence< OUString > SAL_CALL getElementNames(  )
        throw (css::uno::RuntimeException, std::exception) override;

    virtual css::uno::Type SAL_CALL getElementType(  )
        throw (css::uno::RuntimeException, std::exception) override;

    virtual sal_Bool SAL_CALL hasElements()
        throw (css::uno::RuntimeException, std::exception ) override;

    static void set( const css::uno::Reference< css::container::XNameAccess>& xNameAccess, ScDocument *pDoc );
};

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
