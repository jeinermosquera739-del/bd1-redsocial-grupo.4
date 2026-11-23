# Red Social Estudiantil Pascualina — Integración de BD Relacionales con NoSQL en Escenarios de Big Data e IoT

## Datos de la Asignatura
- **Institución:** Institución Universitaria Pascual Bravo
- **Facultad:** Facultad de Ingeniería — Tecnología en Desarrollo de Software
- **Asignatura:** Bases de Datos I
- **Docente:** Oralia Cortes Grajales
- **Año:** 2026

## Integrantes del Equipo
- **LUIS ROJAS CANO**
- **EMILY QUINTERO RIVERA**
- **SOFIA HIDALGO CÓRDOBA**
- **Jeiner Andrés Mosquera Aguirre**

---

## Descripción del Proyecto
Este repositorio contiene el diseño, modelado e implementación técnica de una arquitectura de base de datos híbrida (Relacional + NoSQL) en **PostgreSQL 18 (red_social_hibrida) para la Red Social Estudiantil Pascualina.

El sistema integra la consistencia transaccional del modelo relacional (estudiante) con la flexibilidad de almacenamiento semiestructurado mediante el tipo de dato binario JSONB, índices invertidos GIN para consultas analíticas de alto rendimiento, y particionamiento declarativo por rango de tiempo (PARTITION BY RANGE) orientado a flujos masivos de telemetría de sensores IoT en el campus universitario.

---

## Estructura de Carpetas del Repositorio (red-social-hibrida-postgresql)

La arquitectura del repositorio organiza los tres entregables clave solicitados en la guía:

```text
red-social-hibrida-postgresql/
├── Modelado_Arquitectura/
│   └── diagrama_y_esquema_hibrido.png
│
├── Scripts_SQL/
│   ├── 01_ddl_arquitectura_hibrida.sql
│   ├── 02_dml_insercion_datos.sql
│   └── 03_consultas_analiticas_gin_iot.sql
│
├── Informe_Tecnico/
│   └── Informe_Tecnico_BD_Hibrida.pdf
│
└── README.md
