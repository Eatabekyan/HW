FROM gcc:latest as build


ENV DEBIAN_FRONTEND noninteractive
RUN apt-get update && \
    apt-get -y install gcc mono-mcs && \
    rm -rf /var/lib/apt/lists/*
RUN apt-get update && \
    apt-get install -y \
      libboost-dev libboost-program-options-dev \
      libgtest-dev \
      cmake
RUN apt-get install -y build-essential
RUN apt-get update && apt-get install -y python3.6 python3-distutils python3-pip python3-apt
RUN pip install flask
WORKDIR /opt/techprog
COPY . .
RUN cmake .
RUN make
FROM ubuntu:latest

RUN groupadd -r sample && useradd -r -g sample sample
USER sample

COPY . .

ENTRYPOINT ["python3"] 
CMD ["app.py"]["8898"][8080]



