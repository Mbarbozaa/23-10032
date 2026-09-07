///
/// Image
///

interface Props {
  image: string;
}

const Image = ({ image }: Props) => {
  const src = new URL(`../images/${image}`, import.meta.url).href;
  return (
    <div
      style={{
        display: "inline-block",
        margin: "12px",
        padding: "10px",
        borderRadius: "12px",
        backgroundColor: "#1e1e2e",
        boxShadow: "0 8px 16px rgba(0, 0, 0, 0.4)",
        border: "1px solid rgba(255, 255, 255, 0.1)",
        transition: "transform 0.2s ease-in-out",
      }}
    >
      <div className="splash-image transparent">
        <img
          src={src}
          alt={image}
          style={{
            maxWidth: "100%",
            maxHeight: "350px",
            borderRadius: "8px",
            objectFit: "contain",
            display: "block",
          }}
        />
      </div>
    </div>
  );
};

export default Image;