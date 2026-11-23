   SELECT 
    e.nombre || ' ' || e.apellido AS estudiante_detectado,
    t.tipo_sensor,
    t.fecha_hora,
    t.payload_sensor ->> 'edificio' AS ubicacion_campus,
    COALESCE(
        t.payload_sensor ->> 'ocupacion_actual_porcentaje',
        t.payload_sensor ->> 'aforo_detectado'
    ) AS metrica_ocupacion
FROM telemetria_campus_iot t
INNER JOIN estudiante e ON t.id_estudiante = e.id_estudiante
WHERE t.fecha_hora >= '2026-11-01 00:00:00'
ORDER BY t.fecha_hora DESC;
