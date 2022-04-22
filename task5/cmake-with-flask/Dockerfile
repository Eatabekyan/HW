# В качестве базового образа для сборки используем gcc:latest
FROM gcc:latest as build

# Установим рабочую директорию для сборки GoogleTest
WORKDIR /opt/techprog


# Такая длинная команда обусловлена тем, что
# Docker на каждый RUN порождает отдельный слой,
# Влекущий за собой, в данном случае, ненужный оверхед
RUN apt-get update && \
    apt-get install -y \
      libboost-dev libboost-program-options-dev \
      cmake  

# Скопируем директорию /src в контейнер
ADD . .

# Установим рабочую директорию для сборки проекта
WORKDIR /opt/techprog

# Выполним сборку нашего проекта, а также его тестирование
RUN cmake . && \
    cmake --build . 

# Запуск ---------------------------------------

# В качестве базового образа используем ubuntu:latest
FROM ubuntu:latest

#Скачиваем все необходимые файлы для Python и Flask

RUN apt-get update \
 && apt-get install -y sudo
# Добавим пользователя, потому как в Docker по умолчанию используется root
# Запускать незнакомое приложение под root'ом неприлично :)
RUN adduser --disabled-password --gecos '' tp2022user
RUN adduser tp2022user sudo
RUN echo '%sudo ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers
#RUN groupadd -r tp2022user && useradd -r -g tp2022user tp2022user
USER tp2022user


# Установим рабочую директорию нашего приложения
WORKDIR /opt/techprog

# Скопируем приложение со сборочного контейнера в рабочую директорию
COPY --from=build /opt/techprog .

RUN sudo apt-get update && sudo apt-get install -y python3.6 python3-distutils python3-pip python3-apt
RUN sudo pip install flask


# Установим точку входа
ENTRYPOINT  ["make"]



CMD ["python3"]["app.py"]["8898"]["8080"]


































