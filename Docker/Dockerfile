FROM ubuntu:latest

ENV GOOGLE_TEST_VERSION 1.12.0
ENV CMAKE_VERSION 3.24.2
ENV BOOST_VERSION 1.82.0

RUN apt-get update \
    && apt-get upgrade -y \
    && apt-get install -y \
        build-essential \
        clang \
        clang-format \
        curl \
        doxygen \
        gdb \
        libssl-dev \
        python3-pip \
        vim \
        wget \
    && apt-get clean \
    && rm -r /var/lib/apt/lists/* \
    && mkdir /tmp/src

COPY requirements.txt .
RUN pip3 install -r requirements.txt

# Install CMake
WORKDIR /tmp/src
RUN curl -OL https://github.com/Kitware/CMake/releases/download/v${CMAKE_VERSION}/cmake-${CMAKE_VERSION}.tar.gz \
    && tar zxvf cmake-${CMAKE_VERSION}.tar.gz \
    && cd cmake-${CMAKE_VERSION}/ \
    && ./bootstrap \
    && make \
    && make install

# Install Google Test
WORKDIR /tmp/src
RUN curl -OL https://github.com/google/googletest/archive/release-${GOOGLE_TEST_VERSION}.tar.gz \
    && tar -zxvf release-${GOOGLE_TEST_VERSION}.tar.gz \
    && mkdir ./googletest-release-${GOOGLE_TEST_VERSION}/build \
    && cd /tmp/src/googletest-release-${GOOGLE_TEST_VERSION}/build \
    && cmake .. \
    && make \
    && make install

# Install Boost
WORKDIR /tmp/src
RUN BOOST_VERSION_MOD=$(echo $BOOST_VERSION | tr . _) \
    && wget https://boostorg.jfrog.io/artifactory/main/release/${BOOST_VERSION}/source/boost_${BOOST_VERSION_MOD}.tar.bz2 \
    && tar --bzip2 -xf boost_${BOOST_VERSION_MOD}.tar.bz2 \
    && cd boost_${BOOST_VERSION_MOD} \
    && ./bootstrap.sh --prefix=/usr/local \
    && ./b2 install

WORKDIR /tmp
RUN rm -rf ./src/
