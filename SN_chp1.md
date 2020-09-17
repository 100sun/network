# 1.1 what is the Internet?

## inter + network

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

# 1.2 Network Edge

## Access Networks

* : make network edges(⊃ end hosts) accessible to the network
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

**dedicated** access network 

0. cable or DSL modem, ONT -> splitter
1. Fiber To The Home
2. (central office) Headend
4. Internet Service Provider

### Enterprise / Institutional Network

**dedicated** access network 

0. AP, Ethernet switch
4. Institutional link to ISP

## Wireless Access Networks

connects an end system to the router
wireless LANs: Wireless Fidelity(shared network)
wide-area wireless access (cellular network)

### archi

| 나의 network | network core | 상대방의 network |
| ------------- | ------------- |------------- |
| [end host(무선단말기) ----- AP(기지국)---- edge router]| (router들) | [edge router -----end host]

## links

# 1.3 network core

packet switching, circuit switching, network structure

# 1.4 delay, loss, throughput in networks

# 1.5 protocol layers, service models

# 1.6 networks under attack: security

# 1.7 history
