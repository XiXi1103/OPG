FROM gcc:10
WORKDIR /
COPY ./* ./
RUN g++ test.cpp -o lexical
RUN chmod +x lexical
