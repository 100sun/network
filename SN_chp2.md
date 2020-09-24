# 2.1 principles of network applications

network apps(ex. gmail, youtube, zoom, game) work only on **end systems**

## App Structure

| model | communication | data consumer | data provider | scaling | 
| ---- |---- | ---- | ---- |---- | 
| **client-server model** | process of client <-> process of server | client<br/>on/off<br/>dynamic IP address | server<br/>always on<br/>permanent IP address | data centers↑ | 
| **Peer-2-Peer model** | arbitrary end system <-> arbitrary end system | all devices | all devices | peer↑(self-scalability) | 

## Socket

door: application -> (socket) -> transport -> ...

## Addressing Processes

for http message to web server

### host device -> (permanent 32bit **IP address + port number**(process identifier)) -> host device

* well known port numbers: 80(HTTP), 25(mail)

## Transport Service Requirements

| Transport Service | kinds of app | for | 
| ------ |------ |------ |
| **data integrity** | file transfer, web transactions | no loss<Br/>(<-> loss tolerant) |
| **timing** | Internet telephony, interactive games | time sensitive<Br/>(<-> delay) |
| **throughput** | multimedia | minimum throughput<br/>(<-> elastic) | 

## Internet transport protocols services

| Transport layer protocols | provice O | provide X |
| ------ |------ |------ | ---- |
| TCP | reliable | error, flow, congestion control| minimum throughput guarantee, timing, security |
| UDP | unreliable |  ~ | reliability, flow, congestion control |

## App-layer protocol defines

1. type
2. syntax
3. semantics
4. rules

# 2.2 Web and HTTP

# 2.3 electronic mail (SMTP, POP3, IMAP)

# 2.4 DNS

# 2.5 P2P applications

# 2.6 video streaming and content distribution networks
