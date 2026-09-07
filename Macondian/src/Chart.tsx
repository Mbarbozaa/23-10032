///
/// Chart
///

interface Props {
  data?: number[];
}

const Chart = ({ data = [10, 25, 40, 32, 55, 70, 65, 88, 92, 100] }: Props) => {
  const width = 600;
  const height = 260;
  const padding = 40;

  const maxVal = Math.max(...data, 1);
  const points = data
    .map((val, index) => {
      const x = padding + (index / (data.length - 1 || 1)) * (width - 2 * padding);
      const y = height - padding - (val / maxVal) * (height - 2 * padding);
      return `${x},${y}`;
    })
    .join(" ");

  return (
    <div
      style={{
        background: "#181825",
        padding: "20px",
        borderRadius: "12px",
        boxShadow: "0 8px 24px rgba(0,0,0,0.3)",
        color: "#cdd6f4",
        fontFamily: "sans-serif",
        maxWidth: "650px",
        margin: "20px auto",
      }}
    >
      <h3 style={{ marginTop: 0, color: "#89b4fa", borderBottom: "1px solid #313244", paddingBottom: "10px" }}>
        📊 Visualización de Procesamiento de Señal
      </h3>
      <svg width="100%" height={height} viewBox={`0 0 ${width} ${height}`}>
        {/* Guías de fondo */}
        <line x1={padding} y1={height - padding} x2={width - padding} y2={height - padding} stroke="#45475a" strokeWidth="1" />
        <line x1={padding} y1={padding} x2={padding} y2={height - padding} stroke="#45475a" strokeWidth="1" />

        {/* Línea de tendencia */}
        <polyline fill="none" stroke="#89b4fa" strokeWidth="3" points={points} />

        {/* Puntos de datos */}
        {data.map((val, index) => {
          const x = padding + (index / (data.length - 1 || 1)) * (width - 2 * padding);
          const y = height - padding - (val / maxVal) * (height - 2 * padding);
          return (
            <g key={index}>
              <circle cx={x} cy={y} r="5" fill="#f5e0dc" stroke="#89b4fa" strokeWidth="2" />
              <text x={x} y={y - 10} fill="#a6adc8" fontSize="10" textAnchor="middle">
                {val}
              </text>
            </g>
          );
        })}
      </svg>
    </div>
  );
};

export default Chart;