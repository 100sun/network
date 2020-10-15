# network

[Computer Networking: A Top-Down Approach (7th Edition)](https://www.amazon.com/Computer-Networking-Top-Down-Approach-7th/dp/0133594149?ref_=Oct_s9_apbd_otopr_hd_bw_byR&pf_rd_r=N3BJ8YAB316G1J3JRCNS&pf_rd_p=d52d9aef-6761-537a-b654-84d5a43406db&pf_rd_s=merchandised-search-10&pf_rd_t=BROWSE&pf_rd_i=3747)
<details>
  <summary>class info</summary>

### scoring

* exam 40, 40 
* hw(problems, review) 10 
* being late up to 4 is fine

### syllabus

* [Application layer protocol](#21-principles-of-network-applications)
* Transport layer protocol

<hr>

* Network layer protocol
* Link, physical layer protocol
* Mobile network

</details>

<hr/>

## notes

# 1.1 what is the Internet?

### inter + network

ex. mobile network, home networks, institutional networks

## component

### H/W

* **end hosts**: running network apps on terminals
* **interconnection devices**: router, switch, repeater...
    - **packet switches**: the way to communicate between hosts in the other networks
* links: copper, fiber, radio, wireless...
    - transmission rate: **bandwidth** ⬆ internet speed ⬆

### S/W

* Operating Software
* application programs
* protocols: rules for communications
    - ex. message format, order, action

<hr/>
hosts => network edges => network core

# 1.2 Network Edge

## 1.2.1 Access Networks

: make network edges(⊃ end hosts) accessible to the network
(ISP connects public internet and Local Area Network making an access link )

### architecture

| my network | network core | my network |
| ------------- | ------------- |------------- |
| [end host(wireless) --(wireless)--- AP --(wire)-- edge router]| (routers) | [edge router -----end host]

* transmission rate: bandwidth(bps) ⬆ internet speed ⬆
* (central office) shared / dedicated

### Digital Subscriber Line

**dedicated** access network 

0. DSL modem -> splitter
1. **DSL phone line**
2. (central office) DSL Access Multiplexer
3. voice(~4kHz): telephone network | data(4kHz~): Internet Service Provider

### Cable Network

**shared** access network 

0. cable modem -> splitter
1. **coaxial cable**: cable company provide one signal to multiple users
2. (central office) Cable Modem Termination System
3. Hybrid Fiber Coax
4. Internet Service Provider

### Home Network

0. cable or DSL modem, ONT -> splitter
1. Fiber To The Home
2. (central office) Headend
4. Internet Service Provider

### Enterprise / Institutional Network

0. AP, Ethernet switch
4. Institutional link to ISP

### Wireless Access Networks

**shared** access network 

* wireless LANs: Wireless Fidelity(shared network)
* wide-area wireless access(shared network)

## 1.2.2 Physical Media

: the physical materials that are used to store or transmit information in data communications

* guided: wired
    - Twisted-pair cable: copper wires, behind the ethernet
    - Coaxial cable: copper conductor, broadband
    - Fiber-optic Cable: high speed, low error rate
* unguided: wireless
    - radio link types

# 1.3 Network Core

* connecting network edges(⊃ end hosts) 
* the mesh of interconnected routers
* when sending packets, forwarding from a router to the next router
    - routing: Get a path from source host to destination host using routing algorithms
    - forwarding: Move packets from the before router to the next router using forwarding table

## 1.3.1 Two fundamental approaches to moving data

### comparison

| circuit switching | packet switching |
| ---------------- | ---------------- |
| call setup, resource reservation<br/> : the resources needed along a path | No call setup, no resource reservation |
| multiple users sharing a link<br/> by Frequency Division Multiplexing , Time Division Multiplexing | full link capacity<br/> by dividing into small packets which have their own each destination address<br/> using store-and-forward transmission |
| low speed | 3.5x users but after it.. low Quality Of Service |
| in telephone networks | ~ |

### store-and-forward transmission

* app in source Host ---link(by packets)---> app in destination Host
* how? storing bits until a packet and then forwarding it
* => [total time](#delay)

## 1.3.2 A Network of Networks

Internet = A Network (by ISP) of Networks (end system) 

### hierarchy structure

host < access ISP < regional ISP (peering link) < Internet eXchange Point < Tier 1 ISP or Content Provider<Br/>
<img src="https://cs.pomona.edu/classes/po181u/slides/lec2/images/netofnets2.png" height="200">

* content provider has its own **content provider network** in its own data center

# 1.4 Evaluation Metrics in networks

## 1.4.1 delay

: source~destination seconds

1. nodal **processing** delay: before forwarding a packet, should check its error and destination address
    - opt to the quality of router
2. **queueing** delay: when forwarding one packet, the other packet should wait in a buffer.
    - opt to the number of network users => so variable
    - **traffic intensity** = La/R ↑ ~1 infinite<br/> when packet arrival rate(packet/sec) > output link capacity(L/R) <br/> <=> over the queue -> dropped
3. **transmission** to the link delay when starting to forward: A host send a packet of ***L bits*** over a link with transmission rate ***R bits/sec***, then the time to transmit the packet is ***L/R sec***.  (link transmission rate = link capacity = link bandwidth)
    - opt to bandwidth of output link
4. **propagation** delay in the link: time = length / speed
    - opt to the amount of data
5. => end-end delay: the number of **hop** * L/R 

## 1.4.2 loss

: Packet Loss Rate (<-> Packet Delivery Rate)

* usually in router
* in a buffer when queueing delay, data > queue capacity => dropped
* host: re-transmission, network: waste of resource, user: delay

## 1.4.3 throughput

: sum of traffic <=> how much data has been moved between server and client <Br/>
=> rate: bits/time unit

1. instantaneous: throughput at the peak
2. average: throughput on the average 
    - end-end average throughput == bottleneck link == min(**R<sub>s</sub>, R<sub>c</sub>**, R/10)

# 1.5 protocol layers, service models

## Internet protocol stack

| 5 layers | explanation | protocol | encapsulation | controlled by | 
| ------- | ------- | -----|-----|-----|
| [application](#21-principles-of-network-applications) | support network application | [HTTP](#22-Web-and-HTTP), [SMTP](#23-electronic-mail), [DNS](#24-DNS), FTP | message | user(app developer) |
| **transport** | data transfer process <-> process | TCP, UDP | + segment | OS | 
| **network** | find path | IP, routing protocols | + datagram |OS | 
| **link** | data transfer by hop from source to destination | Ethernet, WiFi | + frame |OS | 
| **physical** | on the wire like cable, radio | bits | Protocol Data Unit |OS | 

* layering: modularization -> maintenance, system update
* encapsulation: message + headers..
    - source -> **switch**(link+physical) -> **router**(network+link+physical) -> destination(only *message + segment* are from source)
    -  always start from physical layer and go up by figuring out the needed info by the headers

# 2.1 principles of network applications

network apps(ex. gmail, youtube, zoom, game) work only on **end systems**

## App Structure

| model | communication | data consumer | data provider | scaling | 
| ---- |---- | ---- | ---- |---- | 
| **client-server model** | process of client <-> process of server | client<br/>on/off<br/>dynamic IP address | server<br/>always on<br/>permanent IP address | data centers↑ | 
| **Peer-2-Peer model** | arbitrary end system <-> arbitrary end system | all devices | all devices | peer↑(self-scalability) | 

## Socket

* A network socket is a software structure within a network node of a computer network that serves as an endpoint for *sending and receiving data across the network*.
* door: application -> (socket) -> transport -> ...

## Addressing Processes

for http message to web server

### host device -> (permanent 32bit **IP address + port number**(process identifier)) -> host device

* well known port numbers: 80(HTTP), 25(mail)

## Protocol

* [email](#23-electronic-mail): SMTP > TCP
* remote terminal access: Telnet > TCP
* [web](#22-Web-and-HTTP): HTTP > TCP
* file transfer: FTP > TCP

|HTTP|SMTP|
|---|---|
|port|80|25|
|object<->data|pull|push|
|in 1 response message|1 object|multiple objects|
|interaction| command(ASCII) + response(status code+phrase)||
|in transport layer|use [TCP](#Internet-transport-protocols-services) connection ∵ reliability||

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

<details>
<summary>words</summary>

#### word

* HyperText Transfer Protocol 
* Round Trip Time
* Uniform Resource Locator
* Carriage Return, Line Feed

</details>

## HTTP response time

* www: Webpage > base html file(frame) > objects > url(obj file loc)
* HTTP layers: application: HTTP > transport: TCP > network: IP > link: ethernet, wifi

### non-persistent HTTP 

1. first object
    1. 1RTT for tcp connection request/response: new *TCP connection [socket](#Socket)* created to initiate tcp connection
    2. 1RTT for http request(URL)/response(base HTML file: file transmission time): that socket deleted to *terminate* tcp connection
2. second object: 2RTT + file transmission time

-> **4RTT**+α => long latency<Br/>
-> then... how about **parallel TCP connection**: 4 sockets(< OS) => overhead

### persistent HTTP 

: no tcp connection more after initiated it

1. first object
    1. 1RTT for tcp: two tcp connection sockets created
    2. 1RTT for http: keep two sockets ()
2. second object
    - 1RTT for http: parallel objects request/response

-> **3RTT**+α

## HTTP format

### request

#### request line

: 1 line 

1. method + URL(after hostname) + version + cr + lf
    - ex. GET /100sun/1.md HTTP/1.0\r\n

#### header lines

: 1<= line

1. field name + : + value + cr + lf
    - ex. Host: www.github.com\r\n
    - ex. user-agent, accept-language, keep-alive([how long](#persistent-HTTP))
2. cr + lf (end of header lines)
    - ex. \r\n

#### body

: optional - like POST

* entire body

## cookies

client can keep user session state in cookie file ex. my id in ebay, amazon

1. HTTP request
    - if first access: A server creates ID
    - if not: send my id by each server with cookie headerline
2. HTTP response msg

## how to reduce delay

1. [Increase Access Link Speed](#1.-origin-server-(+-fatter-access-link)): expensive(2s)
2. [Install Local Web Cache](#2.-origin-server-+-local-web-cache): cheaper and faster(1.2s) but need version checking
3. [Conditional GET method](#3.-Conditional-GET)

### 1. origin server (+ fatter access link)

***need to be fixed***

#### assumptions

* data rate from origin servers to browsers: 1.50Mbps
  + object size * request rate
  + 0.1 Mbits * 15/s = 1.50Mbps
* ***[access](#121-Access-Networks) link rate***: 1.45Mbps

#### consequences

* LAN utilization
    - data rate / LAN availability
    - 1.5Mbps / 1Gbps = 15%
* ***access link utilization***: <= 70: fine
  + access link rate / date rate
  + 1.5Mbps / 1.54Mbps = 99%

#### total delay

* Internet delay = RTT from institutional router to origin servers: 2s
* ***[access delay](#141-delay)*** = queueing delay
  + access link rate / date rate
  + 1. 1.5Mbps / 1.54Mbps ≈ 1 → ∞ = ***minutes***
* LAN delay: μs

=> total delay: 2s + ms + μs ≈ >m
(increase access link bandwidth)
=> total delay: 2s + ms + μs ≈ >2s

### 2. origin server + local web cache

#### assumptions

cache hit rate: 0.4

#### consequences

* 40% requests satisfied at proxy servers
  + 0.4 * μs(delay in LAN) 
* 60% requests satisfied at origin servers
  + data rate from origin servers to browsers<br/>: 1.5Mbps * 0.6 = 0.9Mbps
  + access link utilization<br/>: 99% * 0.6 = 58%
  + RTT from institutional router to origin servers<Br/>: 2s * 0.6
  + access delay<br/>: ≈ 0 ∵ access link utilization is less than 0.7
  + LAN delay<br/>: μs

#### total delay

=> total delay = 2s * 0.6 + μs * 0.4 ≈ >1.2s

#### proxy server

web caches = proxy server

* what is proxy server?
  + client for origin server
  + server for client
* ex? - HTTP request/response
  + client <-> proxy server <-> origin server
  + if same request: client <-> proxy server
* why web caching? 
  + to reduce overhead of origin server
  + to reduce response time for client
  + to support more users for the origin server
  + to reduce traffic of external server on an institution's access link for local ISP

<img src="/web-caching. JPG" height="200"/>

### 3. Conditional GET

* why? objects in web cache have to be up-to-date as same as the original server
* how? 
  + HTTP request: if-modified-since: $date
  + HTTP response: HTTP/1.0 304 Not Modified || HTTP/1.0 200 OK $data

# 2.3 Electronic mail

### Three major components

* user agents: mail reader program e.g. outlook
* mail servers: gmail, …
* protocols: SMTP, POP3, IMAP, …

=> UA: write -> (SMTP) -> message queue of mail server -> (TCP < SMTP) -> mailbox of mail server -> (POP, IMAP, HTTP) -> UA: read

## push

### SMTP

: delivery/storage to receiver’s server

#### transfer phases

1. *handshaking*(TCP): HELO 
2. *message transfer*
3. *closure*: QUIT, closing connection

## pull

Mail access protocol

### POP3

### IMAP

|POP3|IMAP|
|---|---|
|Post Office Protocol ver3|Internet Access Protocol|
|*download & delete* mode(cannot re-read)<br/>*download & keep* mode(copies on different clients)<br/>=>terminate TCP connection|*keep *all messages in one server<br/>=>keep TCP connection|
|*No* mail folder organization|Allows user to organize messages in *folders*|
|*stateless* across sessions|*keep* user state across sessions|

### HTTP

HyperText Transfer Protocol: used in the web-based emails e.g.gmail, hotmail

# 2.4 DNS

Domain Name System

## DNS services

* mapping service: hostname -> (DNS) -> IP address (32 bit)
* host aliasing: alias name(typed URL) -> (DNS) -> canonical name(real URL)
* mail server aliasing
* load distribution: replicated Web servers(many IP addresses correspond to one hostname) ∵ scaling

## how DNS works 

* local DNS server) acts like proxy
* DNS hierarchy) Root DNS server: total 13 > Top Level Domain server: com, org, kr(top-level country domains) > authoritative DNS server: amazon.com, google.com > IP address

### by iterated query

: between local DNS server and one of DNS hierarchy servers

1. client -> local DNS server -> IP address => client: access to that IP address
2. client -> *local DNS server <-> DNS hierarchy* => client: access to that IP address

### by recursive query

: between at upper level and lower level server

1. client -> local DNS server -> IP address => client: access to that IP address
2. client -> *local DNS server -> DNS hierarchy* => client: access to that IP address

-> heavy load on root => **caching**

* local DNS server caches entries about TLD server
* : client -> *local DNS server -> TLD server -> authoritative DNS server => client: access to that IP address

-> cached entries can be out-of-date => **T**ime**T**o**L**ive when mapping

# 2.5 P2P applications

## Pure P2P architecture

different from client-server architecture

* no need for always-on server
* arbitrary end systems directly communicate (A peer can be either client or server)
* changing IP addresses
* good scalability
* e.g. file distribution(BitTorrent), Streaming (KanKan)

 VoIP (Skype) 

# 2.6 video streaming and content distribution networks
