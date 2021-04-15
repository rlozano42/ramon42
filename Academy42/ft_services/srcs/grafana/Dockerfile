FROM alpine:3.12

RUN  apk add --repository http://dl-cdn.alpinelinux.org/alpine/edge/community/ --allow-untrusted --no-cache grafana

WORKDIR /usr/share/grafana

COPY ./telegraf-datasource.yaml /usr/share/grafana/conf/provisioning/datasources/

EXPOSE 3000

ENTRYPOINT grafana-server