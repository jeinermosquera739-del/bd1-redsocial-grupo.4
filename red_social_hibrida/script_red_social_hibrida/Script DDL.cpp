-- 1. Tabla Relacional Base: Estudiantes
CREATE TABLE estudiante (
    id_estudiante SERIAL PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL,
    apellido VARCHAR(100) NOT NULL,
    carrera VARCHAR(100) NOT NULL
);

-- 2. Tabla Híbrida: Publicaciones con metadatos semiestructurados (JSONB)
CREATE TABLE publicacion_enriquecida (
    id_publicacion SERIAL PRIMARY KEY,
    id_estudiante INT NOT NULL REFERENCES estudiante(id_estudiante) ON DELETE CASCADE,
    titulo VARCHAR(200) NOT NULL,
    fecha_creacion TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    metadatos_json JSONB NOT NULL
);

-- Índice GIN para optimizar consultas sobre el campo JSONB (Big Data)
CREATE INDEX idx_pub_metadatos_gin 
ON publicacion_enriquecida USING GIN (metadatos_json);

-- 3. Tabla Optimizada para IoT: Sensores de Campus Inteligente (Particionada)
CREATE TABLE telemetria_campus_iot (
    id_evento BIGSERIAL,
    id_estudiante INT REFERENCES estudiante(id_estudiante),
    tipo_sensor VARCHAR(50) NOT NULL,
    fecha_hora TIMESTAMP NOT NULL,
    payload_sensor JSONB NOT NULL,
    PRIMARY KEY (id_evento, fecha_hora)
) PARTITION BY RANGE (fecha_hora);

-- Partición de rango para noviembre de 2026
CREATE TABLE telemetria_iot_2026_11 
PARTITION OF telemetria_campus_iot
FOR VALUES FROM ('2026-11-01 00:00:00') TO ('2026-12-01 00:00:00');

-- Índice GIN sobre los datos de los sensores IoT
CREATE INDEX idx_iot_payload_gin 
ON telemetria_campus_iot USING GIN (payload_sensor);
