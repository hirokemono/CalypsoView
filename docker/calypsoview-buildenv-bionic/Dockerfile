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
  libglfw3     \
  libglfw3-dev

