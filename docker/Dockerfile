FROM ev3dev/debian-jessie-cross:latest

RUN sudo apt-get update
RUN sudo apt-get install -y apt-utils swig3.0 python-dev git
RUN sudo git clone https://github.com/flosommerfeld/ev3dev-c
RUN sudo rm -rf /var/lib/apt/lists/*
