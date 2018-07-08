################################################################################
#      This file is part of LibreELEC - https://libreelec.tv
#      Copyright (C) 2018-present Team LibreELEC
#
#  LibreELEC is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 2 of the License, or
#  (at your option) any later version.
#
#  LibreELEC is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with LibreELEC.  If not, see <http://www.gnu.org/licenses/>.
################################################################################

PKG_NAME="gbm-rockchip"
PKG_VERSION="master"
PKG_SHA256=""
PKG_ARCH="any"
PKG_LICENSE="Apache"
PKG_SITE=""
PKG_URL=""
PKG_DEPENDS_TARGET="toolchain mali-rockchip"
PKG_SECTION="debug"
PKG_LONGDESC=""
PKG_TOOLCHAIN="manual"
PKG_BUILD_FLAGS="-gold -lto"

make_target() {
  echo "$CC $CFLAGS $LDFLAGS -I$SYSROOT_PREFIX/usr/include/libdrm -shared -fPIC gbm.c -o libgbm.so -lmali -ldrm"
  $CC $CFLAGS $LDFLAGS -I$SYSROOT_PREFIX/usr/include/libdrm -shared -fPIC gbm.c -o libgbm.so -lmali -ldrm
}

makeinstall_target() {
  cd $PKG_BUILD

  mkdir -p $SYSROOT_PREFIX/usr/include
    cp -PRv gbm.h $SYSROOT_PREFIX/usr/include

  mkdir -p $SYSROOT_PREFIX/usr/lib/pkgconfig
    cp -PRv $PKG_DIR/pkgconfig/*.pc $SYSROOT_PREFIX/usr/lib/pkgconfig

  mkdir -p $SYSROOT_PREFIX/usr/lib
    cp -PRv libgbm.so $SYSROOT_PREFIX/usr/lib

  mkdir -p $INSTALL/usr/lib
    cp -PRv libgbm.so $INSTALL/usr/lib
}
