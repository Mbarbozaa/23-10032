///
/// List (Procesamiento de datos crudos)
///

interface Props {
  rawSignal?: string[];
}

const List = ({ rawSignal = ["S1:45", "S2:88", "S1:12", "S3:99", "S2:54"] }: Props) => {
  // Algoritmo de procesamiento: Parsear y filtrar la señal cruda
  const processedData = rawSignal.map((entry, index) => {
    const parts = entry.split(":");
    const sensor = parts[0] || `S${index}`;
    const value = parseFloat(parts[1]) || 0;
    const status = value > 50 ? "Crítico / Alto" : "Normal";

    return { id: index + 1, sensor, value, status };
  });

  return (
    <div style={{ padding: "16px", background: "#1e1e2e", borderRadius: "8px", color: "#cdd6f4" }}>
      <h3 style={{ color: "#89b4fa", marginTop: 0 }}>📋 Datos Procesados de Sensores</h3>
      <table style={{ width: "100%", borderCollapse: "collapse", textAlign: "left" }}>
        <thead>
          <tr style={{ borderBottom: "1px solid #45475a", color: "#f5e0dc" }}>
            <th style={{ padding: "8px" }}>#</th>
            <th style={{ padding: "8px" }}>Sensor</th>
            <th style={{ padding: "8px" }}>Valor Crudo</th>
            <th style={{ padding: "8px" }}>Estado</th>
          </tr>
        </thead>
        <tbody>
          {processedData.map((item) => (
            <tr key={item.id} style={{ borderBottom: "1px solid #313244" }}>
              <td style={{ padding: "8px" }}>{item.id}</td>
              <td style={{ padding: "8px" }}>{item.sensor}</td>
              <td style={{ padding: "8px" }}>{item.value}</td>
              <td style={{ padding: "8px", color: item.value > 50 ? "#f38ba8" : "#a6e3a1" }}>
                {item.status}
              </td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
};

export default List;