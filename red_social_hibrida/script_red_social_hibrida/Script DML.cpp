-- 1. Insertar estudiantes de prueba
INSERT INTO estudiante (nombre, apellido, carrera) VALUES 
('Juan', 'Pérez', 'Ingeniería de Software'),
('María', 'Gómez', 'Ciencia de Datos');

-- 2. Insertar publicaciones con metadatos semiestructurados (JSONB)
INSERT INTO publicacion_enriquecida (id_estudiante, titulo, metadatos_json) VALUES 
(1, 'Hackathon Universitario 2026', '{
    "tipo_contenido": "evento",
    "etiquetas": ["tecnologia", "bases_de_datos", "postgresql"],
    "multimedia": {"formato": "mp4", "duracion_seg": 45},
    "reacciones": {"me_gusta": 124, "me_encanta": 38}
}'),
(2, 'Guía rápida de índices GIN en JSONB', '{
    "tipo_contenido": "articulo",
    "etiquetas": ["nosql", "big_data", "rendimiento"],
    "encuesta": {"pregunta": "¿Usas JSONB en producción?", "votos_si": 85, "votos_no": 12},
    "reacciones": {"me_gusta": 210, "util": 94}
}');

-- 3. Insertar registros de sensores IoT del campus
INSERT INTO telemetria_campus_iot (id_estudiante, tipo_sensor, fecha_hora, payload_sensor) VALUES 
(1, 'acceso_biblioteca', '2026-11-22 08:15:00', '{
    "edificio": "Bloque C - Biblioteca",
    "piso": 2,
    "ocupacion_actual_porcentaje": 78,
    "dispositivo_id": "IOT-BIB-02"
}'),
(2, 'ocupacion_aula', '2026-11-22 09:30:00', '{
    "edificio": "Bloque A - Laboratorios",
    "aula": "Lab-304",
    "temperatura_c": 21.5,
    "aforo_detectado": 28
