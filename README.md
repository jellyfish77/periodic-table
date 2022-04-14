# periodic-table
Implementation of https://www.codewithc.com/modern-periodic-table-c-project/

# Running with Dockerfile

1. Build image with:

    docker build -t periodic .

    This will compile the code.

2. Run Image with:

    docker run -it --rm --name periodic-running periodic

    This will run the code.


See https://hub.docker.com/_/gcc/