FROM alpine

COPY ./bin              /home/bin/
COPY ./etc              /etc/
COPY ./lib              /home/lib/
COPY ./tmp/.gitignore   /home/tmp/

USER    nobody
WORKDIR /home

CMD ["/bin/sh"]
