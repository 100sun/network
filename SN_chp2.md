# 2.1 principles of network **applications**

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

## Protocol

### application layer protocol 

* open protocols: SMTP, HTTP, FTP, Telnet
* proprietary protocols: skype

#### App-layer protocol defines

1. type: request/response message
2. syntax: fields of message
3. semantics: how to interpret fields
4. rules

### underlying transport protocol

#### Transport Service Requirements

| Transport Service | kinds of app | for | 
| ------ |------ |------ |
| **data integrity** | file transfer, web transactions | no loss<Br/>(<-> loss tolerant) |
| **timing** | Internet telephony, interactive games | time sensitive<Br/>(<-> delay) |
| **throughput** | multimedia | minimum throughput<br/>(<-> elastic) | 

#### Internet transport protocols services

| Transport layer protocols | + | - | occasion |
| ------ |------ |------ | ---- |
| **TCP** | reliable | complex -> low speed | email, web, file transfer |
| UDP | fast speed | unreliable | one-time transaction<br/>: streaming multimedia, internet telephony |

* TCP service: connection-oriented by handshaking
    - error control: ~until no data error
    - flow control: sender considers receiver's data capability
    - congestion control: no data overload in router/switch

# 2.2 Web and HTTP

## Web

webpage ⊃ lots of objects <br/>
=> base html file : frame of webpage ⊃ url referencing objects

## HTTP

HyperText Transfer Protocol 

# 2.3 electronic mail (SMTP, POP3, IMAP)

# 2.4 DNS

# 2.5 P2P applications

# 2.6 video streaming and content distribution networks
