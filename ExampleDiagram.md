## Example Diagram for Interactions ###
Documenting with a diagram depicting the situation where the user sends a ping to the seat LED, and then changes the color to Pink and doing sending another ping.
```mermaid
sequenceDiagram
    participant phone
    participant website
    participant particlePhoton
    
    Note over phone: User holds down button
    phone-->>website: Triggers API request
    website-->>particlePhoton: Sends "up" API request
    particlePhoton -->>website: LED turns on
    
    Note over phone: User releases button
    phone-->>website: Triggers API request
    website -->>particlePhoton: Sends "down" API request
    particlePhoton -->>website: LED turns off
    
    Note over phone: User changes color
    phone-->>website: Triggers API request
    website -->>particlePhoton: Sends "pink" API request
    
    Note over phone: User holds down button
    phone-->>website: Triggers API request
    website -->>particlePhoton: Sends "up" API request
    particlePhoton -->>website: LED turns on (pink)

    Note over phone: User releases button
    phone-->>website: Triggers API request
    website -->>particlePhoton: Sends "pink" API request
    particlePhoton -->>website: LED turns off

```
