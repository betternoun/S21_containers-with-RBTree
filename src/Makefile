CC:=g++
CXXFLAGS=-std=c++17 -Wall -Wextra -Werror -pedantic
SRCDIR=.
BUILDDIR=build
LIBDIR=lib_s21_containers
CODE_STYLE=Google

all: install

install: install-containersplus
install-containers:
	$(MAKE) _install SUBPROJECT=containers
install-containersplus: install-containers
	$(MAKE) _install SUBPROJECT=containersplus

clean: _clean

test-style: _clean _start_style

test: _clean _start_style _start_test

test-coverage: _clean _start_style _start_cppcheck_report _start_lizard _start_flawfinder _start_test _start_test_coverage

test-valgrind: _clean _start_style _start_test _start_test_coverage _start_valgrind_ci

test-cppcheck: _clean _start_cppcheck_report
test-lizard: _clean _start_lizard
test-flawfinder: _clean _start_flawfinder
test-main: _clean _start_style _start_test_main

doc: _clean _docs_report

docker-ubuntu_dev: _docker_ubuntu_dev
docker-ubuntu_dev-enter: _docker_ubuntu_dev_enter
docker-ubuntu_dev-off: _docker_ubuntu_dev_off

include makefiles/clean.mk
include makefiles/style.mk
include makefiles/install.mk
include makefiles/test.mk
include makefiles/valgrind.mk
include makefiles/cppcheck.mk
include makefiles/lizard.mk
include makefiles/flawfinder.mk
include makefiles/doxygen.mk
include makefiles/docker.mk
