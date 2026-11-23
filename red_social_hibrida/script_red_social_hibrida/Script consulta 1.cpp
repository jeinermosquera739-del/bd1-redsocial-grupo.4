SELECT 
    e.nombre || ' ' || e.apellido AS autor,
    pe.titulo,
    pe.metadatos_json ->> 'tipo_contenido' AS formato,
    (pe.metadatos_json -> 'reacciones' ->> 'me_gusta')::INT AS total_likes,
    pe.metadatos_json -> 'etiquetas' AS etiquetas
FROM publicacion_enriquecida pe
INNER JOIN estudiante e ON pe.id_estudiante = e.id_estudiante
WHERE pe.metadatos_json @> '{"etiquetas": ["postgresql"]}'
   OR pe.metadatos_json @> '{"etiquetas": ["big_data"]}';
