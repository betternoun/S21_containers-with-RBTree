FROM ubuntu:24.10

RUN apt-get update && apt-get install -y \
    gcc \
    g++ \
    git \
    curl \
    valgrind \
    clang-tools \
    clang-format \
    lcov \
    gzip \
    doxygen \
    python3 \
    python3-pip \
    python3-venv \
    graphviz \
    make \
    cmake \
    cppcheck \
    flawfinder \
    libgtest-dev \
    libgmock-dev \
    libtbb-dev

RUN cd /usr/src/googletest && \
    mkdir -p build && \
    cd build && \
    cmake .. && \
    make && \
    cp lib/*.a /usr/lib && \
    cd /usr/src/googletest && \
    cd && \
    python3 -m venv /root/venv && \
    /root/venv/bin/pip install markdown lizard jinja2

CMD ["/bin/bash"]
