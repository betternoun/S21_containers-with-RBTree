# Установка gitlab-runner в Docker

1. **Создание Docker тома**:
```bash
docker volume create gitlab-runner-config
```
   Эта команда создает новый том (volume) в Docker с именем `gitlab-runner-config`. Тома в Docker используются для постоянного хранения данных, которые могут быть доступны и сохранены даже после остановки или удаления контейнера.

2. **Запуск контейнера GitLab Runner с использованием созданного тома:**
```bash
sudo docker run -d --name gitlab-runner --restart always -v /var/run/docker.sock:/var/run/docker.sock -v gitlab-runner-config:/etc/gitlab-runner gitlab/gitlab-runner:latest
```

   Эта команда запускает новый контейнер Docker с несколькими параметрами:
   - `-d`: Запускает контейнер в фоновом режиме (detached mode).
   - `--name gitlab-runner`: Присваивает контейнеру имя `gitlab-runner`.
   - `--restart always`: Гарантирует, что контейнер будет автоматически перезапускаться, если он остановится по какой-либо причине.
   - `-v /var/run/docker.sock:/var/run/docker.sock`: Монтирует сокет Docker с хост-системы в контейнер. Это позволяет GitLab Runner управлять другими контейнерами Docker.
   - `-v gitlab-runner-config:/etc/gitlab-runner`: Монтирует ранее созданный том `gitlab-runner-config` в папку `/etc/gitlab-runner` внутри контейнера. Это позволяет сохранять конфигурацию GitLab Runner даже после перезапуска или удаления контейнера.
   - `gitlab/gitlab-runner:latest`: Имя образа, который будет использован для создания контейнера. В данном случае используется последняя версия образа GitLab Runner.

``` bash
sudo docker run --rm -it -v gitlab-runner-config:/etc/gitlab-runner gitlab/gitlab-runner:latest register
```
> Регистрируем runner

```zsh
Enter the GitLab instance URL: https://repos.21-school.ru
Enter the registration token: ***
Enter an executor: docker
Enter the default Docker image: ubuntu:24.10
```
> Настройка
