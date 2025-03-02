FROM ubuntu:24.10

RUN apt-get update && apt-get install -y \
    gcc \
    g++ \
    git \
    tree \
    curl \
    zsh \
    autojump \
    micro \
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
    rm -rf build

RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)" "" --unattended && \
    git clone https://github.com/zsh-users/zsh-autosuggestions /root/.oh-my-zsh/custom/plugins/zsh-autosuggestions && \
    git clone https://github.com/zsh-users/zsh-syntax-highlighting.git /root/.oh-my-zsh/custom/plugins/zsh-syntax-highlighting && \
    sed -i 's/plugins=(git)/plugins=(git zsh-autosuggestions zsh-syntax-highlighting autojump)/g' /root/.zshrc && \
    python3 -m venv /root/venv && \
    /root/venv/bin/pip install markdown lizard jinja2 && \
    mkdir -p /root/project

CMD ["/usr/bin/zsh"]
