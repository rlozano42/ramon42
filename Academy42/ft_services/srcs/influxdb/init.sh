# Start influxdb

influx -execute "CREATE DATABASE ft_services"
influx -execute "CREATE USER rlozano WITH PASSWORD 'rlozano'"
influx -execute "GRANT ALL ON influxdb TO rlozano"