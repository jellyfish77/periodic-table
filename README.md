# periodic-table

Implementation of https://www.codewithc.com/modern-periodic-table-c-project/

https://en.wikipedia.org/wiki/Periodic_table

# Running with Dockerfile

## Build and run the Container

1. Build image 'periodic' with:

        docker build -t periodic .

    or:

        docker build -t ottoq/periodic:0.1 --no-cache  .


    This will also compile the code.

2. Run container as "periodic-container":

        docker run -it --rm --name periodic-container periodic

    or:

        docker run -it --rm --name periodic-container ottoq/periodic:0.1

    This will also run the code.

## Login to Container with zsh

    docker exec -it periodic-container zsh

See https://hub.docker.com/_/gcc/