FROM gcc:14-bookworm
MAINTAINER "Emily Portin <portin.emily@protonmail.com>"

SHELL ["/bin/bash", "-c"]

RUN apt-get update --yes --quiet \
 && DEBIAN_FRONTEND=noninteractive apt-get install --yes --quiet \
      curl \
      wget \
      software-properties-common \
      gnupg

RUN curl --location https://github.com/Kitware/CMake/releases/download/v3.25.1/cmake-3.25.1.tar.gz --output cmake.tar.gz \
 && mkdir cmake \
 && tar xf cmake.tar.gz --directory=cmake --strip-components 1 \
 && pushd cmake \
 && ./bootstrap --parallel=$(nproc) \
 && make -j$(nproc) \
 && make install \
 && popd \
 && rm -rf cmake \
 && rm -rf cmake.tar.gz

RUN mkdir llvm \
 && pushd llvm \
 && curl --location https://apt.llvm.org/llvm.sh --output llvm.sh \
 && chmod +x llvm.sh \
 && ./llvm.sh 19 \
 && popd \
 && rm -rf llvm

RUN rm -rf /var/lib/apt/lists/* \
 && apt-get clean --yes --quiet
