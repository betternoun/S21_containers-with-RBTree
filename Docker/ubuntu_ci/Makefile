IMAGE=golikvn/s21_containers

all: build push

build:
	docker build -t $(IMAGE) .

push:
	docker push $(IMAGE):latest
