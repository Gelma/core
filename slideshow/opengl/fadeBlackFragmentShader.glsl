/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*************************************************************************
 *
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * Copyright 2015 by Collabora, Ltd.
 *
 * OpenOffice.org - a multi-platform office productivity suite
 *
 * This file is part of OpenOffice.org.
 *
 * OpenOffice.org is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License version 3
 * only, as published by the Free Software Foundation.
 *
 * OpenOffice.org is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License version 3 for more details
 * (a copy is included in the LICENSE file that accompanied this code).
 *
 * You should have received a copy of the GNU Lesser General Public License
 * version 3 along with OpenOffice.org.  If not, see
 * <http://www.openoffice.org/license.html>
 * for a copy of the LGPLv3 License.
 *
 ************************************************************************/

#version 120

uniform sampler2D leavingSlideTexture;
uniform sampler2D enteringSlideTexture;
uniform float time;
varying vec2 v_texturePosition;

void main() {
    vec4 black = vec4(0.0, 0.0, 0.0, 1.0);
    vec4 texel;
    float amount;
    if (time < 0.5) {
        texel = texture2D(leavingSlideTexture, v_texturePosition);
        amount = time * 2;
    } else {
        texel = texture2D(enteringSlideTexture, v_texturePosition);
        amount = (1.0 - time) * 2;
    }
    gl_FragColor = mix(texel, black, amount);
}

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
