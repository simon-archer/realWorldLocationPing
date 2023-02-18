## Example Diagram for Interactions

Documenting with a diagram depicting the situation where the user sends a ping to the seat LED, and then changes the color to Pink and doing sending another ping.

```mermaid
sequenceDiagram
phone((Phone)) -->>|Sends "up" API request| website((Website))
    website -->>|Sends "down" API request| particlePhoton((Particle Photon))
    particlePhoton -->>|LED turns on| website
    website -->>|Sends "pink" API request| particlePhoton
    particlePhoton -->>|LED turns pink| website
    website -->>|Sends "up" API request| particlePhoton
    particlePhoton -->>|LED turns on| website
```
