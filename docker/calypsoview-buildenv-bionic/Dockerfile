FROM ubuntu:bionic

RUN apt update && \
  DEBIAN_FRONTEND='noninteractive' \
  DEBCONF_NONINTERACTIVE_SEEN='true' \
  apt install --yes \
  build-essential \
  doxygen \
  gfortran \
  git \
  pkg-config   \
  zlib1g \
  zlib1g-dev \
  libpng-dev \
  libgtk-3-dev \
  libglfw3-dev

