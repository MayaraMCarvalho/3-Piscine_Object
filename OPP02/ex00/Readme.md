# README — PISCINE OBJECT · Module 02 — UML

**Autor:** **_macarval_**

**Diretório:** `ex00/`

**Arquivo principal:** `ex00/subject.png`

---

## 1. Visão Geral

Este repositório contém a modelagem UML pedida no *subject* do exercício: um **diagrama de classes** que modela um sistema veicular simplificado (Motor, Transmissão, Direção, Freios, Cockpit, Eletrônica). O objetivo é representar classes, atributos, métodos e relações (herança, agregação, composição, associação) de forma clara e consistente, seguindo as recomendações do enunciado.

> Entrega obrigatória: `ex00/subject.png` (PNG do diagrama de classes). Opcional: diagramas de sequência e documentação adicional.

---

## 2. Estrutura do repositório (esperada)

```
ex00/
├─ subject.png            # Diagrama de classes final (obrigatório)
├─ sequence_accelerate.png  # (opcional) Diagrama de sequência: Acelerar
├─ sequence_brake.png       # (opcional) Diagrama de sequência: Frear
└─ README.md              # Este arquivo
```

---

## 3. Descrição resumida do modelo

O diagrama modela as seguintes entidades (resumo):

* `LinkablePart` — classe abstrata com `execute(float p_pression)`.
* `Injector`, `BrakeController` — implementam `LinkablePart`.
* `Wheel`, `Gear`, `GearLever`, `Transmission`, `Crankshaft`, `ExplosionChamber`, `Motor`, `Pedal`, `Direction`, `DAE`, `SteerWheel`, `Brake`, `Cockpit`, `Electronics`, `Car`.

Decisões de modelagem (breve):

* **Composição** onde a vida do componente depende do dono (ex.: `Motor` → `ExplosionChamber` interno).
* **Agregação** para coleções de objetos que podem existir independentemente (ex.: `Transmission` -> *vector* de `Wheel*`).
* `GearLever` modelado como **singleton** (`<<singleton>>`), conforme subject.
* `LinkablePart` é abstrata (método virtual puro). Classes que recebem comando (`Pedal`) apontam para `LinkablePart` (polimorfismo).

---

## 4. Multiplicidades sugeridas (exemplos práticos)

* `Direction` → `Wheel` : `2..*` (duas ou mais rodas vinculadas à direção)
* `Transmission` → `Wheel` : `0..*` (transmissão pode não ter wheels conectadas em modelos isolados)
* `Motor` contém `Injector`, `ExplosionChamber`, `Crankshaft` : `1` (composição)
* `Car` contém `BrakeController`, `Direction`, `Transmission`, `Motor`, `Electronics`, `Cockpit` : `1`

> Ajuste multiplicidades se você tiver motivos específicos (ex.: veículo com 4 rodas exatas: use `4`).

---

## 5. Visibilidade e nomes (convenções)

* Atributos privados: prefixo `-` (ex.: `- demultiplier: int`).
* Métodos públicos: prefixo `+` (ex.: `+ void execute(float p_pression)`).
* Métodos/propriedades protegidos: `#` quando necessário.

Sugestão: mantenha atributos privados e forneça getters/setters públicos apenas quando necessário para a lógica de domínio.

---

## 6. Diagramas de sequência (bônus) — cenários sugeridos

1. **Acelerar** (Pedal → Injector → ExplosionChamber → Crankshaft → Transmission → Wheel)
2. **Frear** (Pedal/Freio → BrakeController → Brake → Wheel)
3. **Girar** (SteerWheel → DAE → Direction → Wheel)

Crie arquivos `sequence_accelerate.puml`, etc., e gere PNGs com PlantUML ou exporte do draw.io.

---

## 7. Justificativas que você deve ter prontas para a defesa

* Por que usar composição em `Motor` vs agregação em `Transmission`?
* Por que `GearLever` é `<<singleton>>` (restrição de domínio: existe apenas uma alavanca de câmbio por cockpit)?
* Por que `Pedal` referencia `LinkablePart` por ponteiro (polimorfismo) em vez de referenciar um tipo concreto?
* Como a modelagem possibilita estender o sistema (ex.: adicionar `Turbo` ou `ABS`)?

---
