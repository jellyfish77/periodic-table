FROM ottoq/ubuntu:0.5
COPY . /usr/src/periodic
WORKDIR /usr/src/periodic
RUN gcc -o periodic main.c -lm -Ofast
CMD ["./periodic"]